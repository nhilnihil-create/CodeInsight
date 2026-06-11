#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_set<string> mem;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                string tmp = to_string(i) + to_string(j) + to_string(k);
                int idx = 0;
                for(int x=0;x<n && idx < 3;x++){
                    if(s[x] == tmp[idx]){
                        idx++;
                    }
                }

                if(idx==3){
                    mem.insert(tmp);
                }
            }
        }
    }
    cout<<(int)mem.size()<<"\n";
    return 0;

}


