#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    string s;cin>>s;
    vector<int> a;a.push_back(1);
    int length=s.length();
    
    int res[s.length()+1];
    for(int i=0;i<=length;i++)res[i]=0;
    

    for(int i=1;i<length;i++){
        if(s[i]==s[i-1]){int l=a.size();a[l-1]=a[l-1]+1;} 
        else a.push_back(1);
    }
    
     
    int size = a.size();
    int sum=0;
    for(int i=0;i<size/2;i++){
        if(a[2*i]%2==0){
            res[a[2*i]+sum]+=a[2*i]/2;
            res[a[2*i]+sum+1]+=a[2*i]/2;
        }
        else{
            res[a[2*i]+sum]+=(a[2*i]-1)/2+1;
            res[a[2*i]+sum+1]+=(a[2*i]-1)/2;
        }
        if(a[2*i+1]%2==0){
            res[a[2*i]+sum]+=a[2*i+1]/2;
            res[a[2*i]+sum+1]+=a[2*i+1]/2;
        }
        else{
            res[a[2*i]+sum]+=(a[2*i+1]-1)/2;
            res[a[2*i]+sum+1]+=(a[2*i+1]-1)/2+1;
        }


        sum+=a[2*i]+a[2*i+1];
    }
    for(int i=1;i<=length;i++)cout <<res[i]<<endl;
    
  //for(int i=0;i<a.size();i++)cout<<a[i]<<endl;
  //cout << length<<endl;
}