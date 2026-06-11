
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int size=s.size();

    string rev =s;
    reverse(all(rev));
    if(s != rev){
        cout << "No" << endl;
        return 0;
    }

    string front = s.substr(0,size/2);
    string revfro = front;
    reverse(all(revfro));
    if(front != revfro){
        cout << "No" << endl;
        return 0;
    }

    string back = s.substr(size/2+1,size/2);
    string revback = back;
    reverse(all(revback));
    if(back != revback){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

}