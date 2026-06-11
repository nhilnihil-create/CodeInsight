#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e18
typedef long long ll;
typedef pair<int,int> P;



int main(void){
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d;
    cin>>s;
    if(c<d){
        for(int i=b-1;i<d-1;i++){
            if(s[i]=='#'){
                if(s[i+1]=='#'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        for(int i = a-1;i<c-1;i++){
            if(s[i]=='#'){
                if(s[i+1]=='#'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
    }
    else{
        for(int i=b-1;i<d-1;i++){
            if(s[i]=='#'){
                if(s[i+1]=='#'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        for(int i = a-1;i<c-1;i++){
            if(s[i]=='#'){
                if(s[i+1]=='#'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        int len = 0;
        bool can = false;
        for(int i=b-1;i<=d-1;i++){
            if(i+1>n)continue;
            if(s[i-1]=='.'){
                if(s[i]=='.'){
                    if(s[i+1]=='.'){
                        can = true;
                        break;
                    }
                }
            }
        }
        if(can){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
	return 0; 
}