#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    set<string>s;
    while(n--){
        string ss;
        cin>>ss;
        s.insert(ss);
    }
    cout<<s.size()<<endl;
}
