
#include <unistd.h>

int n;
long long int A[100000];

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

char buf[2100000];
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
  int i;
  long long int a=0, b, c, z=0;
  readall();
  n = read_uintll();
  for(i=0;i<n;i++){
    A[i] = read_uintll();
    a ^= A[i];
  }

  for(b=1LL<<59;b;b>>=1){
    if(b&a) continue;
    for(i=0;i<n;i++){
      if(A[i]&b) break;
    }
    if(i==n) continue;
    if(!(z&b)) z ^= A[i];
    c = A[i];
    for(;i<n;i++){
      if(A[i]&b) A[i] ^= c;
    }
  }

  write_uintll(2*(z&~a) + a);
  writeall();

  return 0;
}
