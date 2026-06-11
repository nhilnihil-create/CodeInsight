#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,m,tmp,cnt=0;
  vector <int> a,spread;

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>tmp;
    a.push_back(tmp);
  }
  for(int i=0,tmp=1;tmp<=n;i++){ //make spread vector                                                                                                                                          
    spread.insert(spread.begin(),tmp);
    tmp=3*tmp+1;
  }
  m=spread.size();
  cout<<m<<endl; //output spread amount                                                                                                                                                        
  for(int i=0;i<m-1;i++) cout<<spread[i]<<" ";
  cout<<spread[m-1]<<endl; //output all spread                                                                                                                                                 
  for(int k=0;k<m;k++) for(int i=0;i+spread[k]<n;i++){
      int end=i+spread[k],first=i%spread[k]; //list first                                                                                                                                      
      // for(int j=1;j<amount;j++){ //inserting sort                                                                                                                                           
        if(a[end]>a[end-spread[k]]) continue;
        int l;
        for(l=1;l<(end-first)/spread[k]+1;l++){
          if(a[end-(l-1)*spread[k]]<a[end-l*spread[k]]){
            swap(a[end-(l-1)*spread[k]],a[end-l*spread[k]]);
            cnt++;
          } else break;
        }
        // cout<<"check vector cnt:"<<cnt<<endl; //debug                                                                                                                                       
        // for(int i=0;i<n-1;i++) cout<<a[i]<<" ";                                                                                                                                             
        // cout<<a[n-1]<<endl<<endl;                                                                                                                                                           
    }
  cout<<cnt<<endl; //output cnt&answer vector                                                                                                                                                  
  for(int i=0;i<n;i++) cout<<a[i]<<endl;
  return 0;
}