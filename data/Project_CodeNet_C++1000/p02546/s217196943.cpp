#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ll long long
int main()
{
    faster();
    string s1;
    cin>>s1;
    string tmp;
    tmp = s1.substr(s1.length()-1,1);
    if(tmp == "s"){
        s1 += "es";
    }
    else{
        s1 += 's';
    }
    cout<<s1<<endl;

    return 0;
}




