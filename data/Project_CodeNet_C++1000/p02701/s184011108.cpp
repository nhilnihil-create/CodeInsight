#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
set<string>st;

int main()
{
    int N;
    cin>>N;
    int cnt=0;
    while(N--){
        string s;
        cin>>s;
        if(st.find(s)!=st.end())continue;
        cnt++;
        st.insert(s);
    }
    cout<<cnt;
}
