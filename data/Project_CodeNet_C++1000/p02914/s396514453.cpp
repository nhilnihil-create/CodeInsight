#include <unistd.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

int n;
long long int B[60];

char ibuf[4000000];
char *ibufe = ibuf-1;

void readall(){
  int k, t = 0;
  while((k=read(STDIN_FILENO, ibuf+t, sizeof(ibuf)-t))>0) t += k;
}

long long int read_uintll(){
  long long int x=0;
  while(*(++ibufe) <'0');
  do {
    x *= 10;
    x += *ibufe-'0';
  } while(*(++ibufe) >='0');

  return x;
}

char buf[100];
char *bufe = buf;

void write_uintll(long long int x){
  int i;
  static char tmp[14];
  if(x==0){
    *bufe++ = '0';
    *bufe++ = '\n';
    return;
  }

  for(i=0; x; i++){
    tmp[i] = '0' + x % 10;
    x /= 10;
  }
  for(i--; i >= 0; i--){
    *bufe++ = tmp[i];
  }
  *bufe++ = '\n';
}

void writeall(){
  int k, t = 0;
  while((k=write(STDOUT_FILENO, buf+t, bufe-buf-t))>0) t += k;
}



int main(){
  int i, j;
  long long int a=0, z=0;
  readall();
  n = read_uintll();
  for(i=0;i<n;i++){
    long long int x = read_uintll();
    if(!x) continue;
    a ^= x;
    for(j=59;j>=0;j--){
      x = MIN(x, x^B[j]);
    }
    if(x) B[63-__builtin_clzll(x)] = x;
  }
  for(j=0;j<60;j++){
    B[j] &= ~a;
    if(!B[j]) continue;
    if(a&(1LL<<j)){
      int k = 63-__builtin_clzll(B[j]);
      for(;k>=0;k--) B[j] = MIN(B[j], B[j]^B[k]);
      if(B[j]) B[63-__builtin_clzll(B[j])] = B[j];
      B[j] = 0;
    }
  }
  for(j=59;j>=0;j--) z = MAX(z, z^B[j]);

  write_uintll(2*z + a);
  writeall();

  return 0;
}
