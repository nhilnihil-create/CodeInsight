#include<iostream>
using namespace std;

int max(int a,int b)
{
 if(a>=b) return a;
 else return b;
}

int main()
{
 int N,M;
 long int K;
 cin >> N >> M >> K;
 long int sum_A[N+1];
 long int sum_B[M+1];
 sum_A[0] = 0;
 sum_B[0] = 0;

 int s_max = 0;
 long int tmp1 = 0;

 int t_max = 0;
 long int tmp2 = 0;

 for(int i=0;i<N;i++){
     long int a_i; cin >> a_i;
     tmp1 += a_i;
     if(tmp1 <= K) s_max++;
     sum_A[i+1] = tmp1;
 }
 for(int i=0;i<M;i++){
     long int b_i; cin >> b_i;
     tmp2 += b_i;
     if(tmp2 <= K) t_max++;
     sum_B[i+1] = tmp2;
 }

 int ans = 0;
 for(int i=0;i<=s_max;i++){
     long int rest = K-sum_A[i];
     int left = 0;
     int right = t_max;
     while(left<=right){
         int mid = (int)(left+right)/2;
         if(sum_B[mid]<=rest) left = mid+1;
         else right = mid-1;
     }
     ans = max(ans,i+left-1);
 }
 cout << ans << endl;
 return 0;
}