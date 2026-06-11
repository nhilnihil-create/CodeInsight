#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define  fastIO    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  endl        "\n";
#define  pi          2*acos(0.0)
#define  inf         LONG_MAX
#define  size        1e5

int main(){
    fastIO;
    //testCase
    string str;         cin>>str;
    char c[str.length()];
    strcpy(c, str.c_str());
    sort(c,(sizeof(c)/sizeof(c[0]))+c );
    //cout<<c<<endl;
    if(c[1]!=c[2] && c[0]==c[1] && c[2]==c[3]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
