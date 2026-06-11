#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    string in;
    cin>>in;
    int ans=0;
    for(int i=0,j=in.length()-1;i<in.length()/2;i++,j--){
        if(in[i]!=in[j]){
            ans++;
        }
    }
    cout<<ans<<endl;
}

