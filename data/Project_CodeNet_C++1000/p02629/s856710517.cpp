#include<bits/stdc++.h>
using namespace std;
#define mx 38461538461538
typedef long long int ll;
int main(){
    ll n,m;
    cin>>n;
    vector<char>v;
    deque<char>duck;
    v.push_back('z');
    v.push_back('a');
    for(int i=1;i<26;i++){
        v.push_back('a'+i);
    }
    while(n!=0){
       if(n%26==0){
        duck.push_front(v[n%26]);
        n=(n/26)-1;
       }
       else{
        duck.push_front(v[n%26]);
        n=n/26;
       }
    }
    for(int i=0;i<duck.size();i++)cout<<duck[i];
    cout<<endl;
    duck.clear();
    return 0;
}
