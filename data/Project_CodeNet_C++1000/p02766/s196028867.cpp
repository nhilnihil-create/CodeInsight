#include <bits/stdc++.h>
using namespace std;

int DIG_K (int meas,int K){
  int ans =0;
  int data=0;
  
  data =meas;
  while(data > 0){
    data /= K;
    ans++;
  }
  
  vector<int> DIG(ans);
  data = meas;
  for (int i=0;i<ans;i++){
    DIG.at(i) = data % K;
    data /= K;
  }
  
  //順番反転
  reverse(DIG.begin(),DIG.end());
  
  //for (int i=0;i<ans;i++)
    //cout<<DIG.at(i)<<" ";
  
  //cout<<endl;
  
	return ans;
}

int main(){
  int N,K;//データ
  int data;
  int ans;
  
  cin>>N>>K;
  
  ans=DIG_K(N,K);
  
  cout << ans << endl;
}

  