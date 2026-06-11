#include <stdio.h>
#include <vector>

using namespace std;

int p[5010],c[5010];
bool flag[5010];

long long check_max0(vector<int> &c, int size, int len){
  long long ans = 0;
  for (int i=0; i<size; ++i){
    long long tmp = 0;
    for (int j=0; j<len; ++j){
      tmp += c[(i+j)%size];
      if (tmp > ans) ans = tmp;
    }
  }
  return ans;
}

long long check_max1(vector<int> &c, int size, int len){
  long long ans = c[0];
  for (int i=0; i<size; ++i){
    long long tmp = 0;
    for (int j=0; j<len; ++j){
      tmp += c[(i+j)%size];
      if (tmp > ans) ans = tmp;
    }
  }
  return ans;
}

int main(){
  int n, k;
  scanf("%d%d",&n,&k);
  for (int i=1;i<=n;++i)
    scanf("%d",&p[i]);
  for (int i=1;i<=n;++i)
    scanf("%d",&c[i]);
  for (int i=1;i<=n;++i)
    flag[i] = true;

  long long ans = c[1];

  for (int i=1; i<=n; ++i){
    if (flag[i]){
      vector<int> _c;
      int now = i;
      while( flag[now] ){
        _c.push_back( c[now] );
        flag[now] = false;
        now = p[now];
      }
      int len = _c.size();
      long long sum = 0;
      for (int _i=0; _i<len; ++_i)
        sum += _c[_i];

      if ( k>=len ){
        long long tmp_ans = sum * ( k / len ) + check_max0(_c, len, k%len);
        if (tmp_ans > ans ) ans = tmp_ans;
        
        tmp_ans = sum * ( k / len -1 ) + check_max1(_c, len, len);
        if (tmp_ans > ans ) ans = tmp_ans;
      }
      long long tmp_ans = check_max1(_c, len, min( len, k ));
      if (tmp_ans > ans ) ans = tmp_ans;
      //printf("a %d %d\n",i, tmp_ans);
    }
  }
  printf("%lld\n",ans);

}
