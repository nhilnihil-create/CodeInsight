#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int N,M;
vector<int>s;
vector<int>c;

bool OK(string str_digit){
        if(str_digit.size()!=N)return false;
        for(int j=0;j<M;j++)if(str_digit[s[j]-1]!=(char)(c[j]+'0'))return false;
        return true;
}

string solve(){
    for(int i=0;i<=999;i++){
        stringstream iss;iss<<i;
        string str_digit=iss.str();
        if(OK(str_digit))return str_digit;
    }
    return "-1";
}

int main() {
    cin >> N >> M;
    s.resize(M);c.resize(M);
    for(int i=0;i<M;i++)cin>>s[i]>>c[i];
    cout<<solve();
    return 0;
}