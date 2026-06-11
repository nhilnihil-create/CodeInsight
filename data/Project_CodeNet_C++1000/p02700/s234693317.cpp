#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h1,s1,h2,s2;

    cin >> h1 >> s1 >> h2 >> s2;
    while(h1 > 0 && h2>0){
        h2-=s1;
        if(h2<=0){
            cout << "Yes"; return 0;
        }
        h1-=s2;
        if(h1<=0){
            cout << "No"; return 0;
        }
    }

    return 0;
}
