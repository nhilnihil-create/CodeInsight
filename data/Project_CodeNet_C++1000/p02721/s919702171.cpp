#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,c;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    vector<int>pos(k+1);
    pos[k]=200005;
    int crpos=-200005;
    int crk=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            if(crk<k&&i-crpos>c){
                pos[crk]=i;
                crpos=i;
                crk++;
            }
        }
    }
    vector<int>ans;
    int crvld=n-1;
    for(int i=k-1;i>=0;i--){
        while(s[crvld]=='x'||pos[i+1]-crvld<=c) crvld--;
        if(crvld==pos[i]){
            ans.push_back(pos[i]+1);
        }else{
            pos[i]=crvld;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << '\n';
    return 0;
}
/***
11 3 2
ooxxxoxxxoo
*/
