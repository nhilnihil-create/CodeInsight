                           //SILENT KILLER
#include<bits/stdc++.h>
//typedef long long ll;
using namespace std;
int main()
{string s, ss;
    cin >> s >> ss;
    bool ans = 1;

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != ss[i])
            ans=0;


    }if(ans)
    cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;



}











