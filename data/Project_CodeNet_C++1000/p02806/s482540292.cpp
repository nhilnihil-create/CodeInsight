#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string>s(N);
    vector<int>t(N);
    int zenbu = 0;
    for(int i = 0; i < N; i++) {
        cin>>s[i]>>t[i];
        zenbu+=t[i];
    }
    string X; 
    cin >> X;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(s[i] == X) {
            ans+=t[i];
            break;
        }
        else{
            ans += t[i];
        }
    }
    cout << zenbu-ans << endl;
}

