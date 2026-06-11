#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;
  cin>>N;
  double sum=0,count=1;
  vector<pair<int,int>> xy(N);
  vector<int> v(N);
  for(int i=0; i<N; i++){
    cin>>xy.at(i).first>>xy.at(i).second;
    v.at(i)=i;
  }
  do{
    for(int i=0; i<N-1; i++){
      sum+=sqrt(pow((xy.at(v.at(i)).first)-(xy.at(v.at(i+1)).first),2)+pow((xy.at(v.at(i)).second)-(xy.at(v.at(i+1)).second),2));
    }
  }while(next_permutation(v.begin(),v.end()));
  for(int i=1; i<=N; i++){
    count*=i;
  }
  sum/=count;
  //cout<<sum<<endl<<count<<endl;
  printf("%.10f\n",sum);
}
