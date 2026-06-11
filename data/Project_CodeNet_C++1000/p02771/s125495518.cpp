#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
 
#define test        int tc;cin>>tc;while(tc--)

bool check(string str){

    for(int i=1;str[i];i++){
        if(str[i]!=str[0]){
            for(int j=i+1;str[j];j++){
                if(str[j]==str[0])
                    return 1;
            }
        }
    }
    return 0;
}

int32_t main(){
        
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && a!=c){
        cout<<"Yes"<<endl;
    }
    else if(a==c && a!=b){
        cout<<"Yes"<<endl;
    }
    else if(b==c && b!=a)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
}
