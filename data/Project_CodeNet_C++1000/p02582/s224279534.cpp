#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0); //Don't delete this line!
    string s;
    cin >> s;
    int maxx=0,strk=0;
    for(int i=0;i<3;i++){
        if(s[i]=='R'){
            strk++;
            maxx = max(maxx,strk);
        }
        else strk=0;
    }
    cout << maxx;
}
