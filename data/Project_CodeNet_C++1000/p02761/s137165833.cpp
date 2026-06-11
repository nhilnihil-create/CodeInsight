#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int i, vector<int> &s, vector<int> &c){
    bool ans = true;
    string S;
    S = to_string(i);
    for(int j=0; j<s.size(); j++){
        if(S.at(s.at(j))-'0' != c.at(j)){
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> s(m),c(m);
    for(int i=0; i<m; i++){
        cin >> s.at(i) >> c.at(i);
        s.at(i)--;
    }
    int start,end;
    if(n==1) start=0;
    else start = pow(10,n-1);
    end = pow(10,n)-1;
    for(int i=start; i<=end; i++){
        if(check(i, s, c)){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}