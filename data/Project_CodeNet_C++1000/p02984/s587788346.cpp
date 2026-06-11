#include<iostream>
#include<vector>
using namespace std;

int main()
{
 vector<long int> L;
 int N;
 long int total=0;
 cin >> N;
 for(int i=0;i<N;i++){
     long int A;
     cin >> A;
     total+=A;
     L.push_back(A);
 }
 vector<long int> ans;

 long int tmp=0;
 for(int i=2;i<=N-1;i+=2){
     tmp+=2*L[i-1];
 }
 ans.push_back(total-tmp);
 for(int i=0;i<N-1;i++){
     ans.push_back(2*L[i]-ans[i]);
     cout << ans[i] << " ";
 }
 cout << ans[N-1] << endl;
 return 0;
}