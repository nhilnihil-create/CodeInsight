#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;


int mp[2100]={0};
int main() {
    string s;
    cin>>s;
    int num=0;
    int ans=0;
    mp[0]=1;

    int ten=10;
    for (int i=s.size()-1;i>=0;i--) {
        num+=(s[i]-'0')*ten;
        num%=2019;
        ten=ten*10%2019;
        mp[num]+=1;
    }

    //for (int i=0;i<2019;i++) if (mp[i]) cout<<i<<" "<<mp[i]<<endl;
    for (int i=0;i<2019;i++)
        ans+=mp[i]*(mp[i]-1)/2;
    cout<<ans<<endl;
    return 0;
}
