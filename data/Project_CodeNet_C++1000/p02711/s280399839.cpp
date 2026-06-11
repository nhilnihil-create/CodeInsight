#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    string s =to_string(n);

    if(count(s.begin(),s.end(),'7')>0){
        cout<<"Yes\n";

    }
    else{
        cout<<"No\n";
    }


    return 0;
}
