#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    std::map<int, int> r;
    std::map<int, int> g;
    std::map<int, int> b;
    for (int i=0;i<n;i++) {
        if (s[i]=='R') {
            r.emplace(i+1,1);
        } else if (s[i]=='G') {
            g.emplace(i+1,1);
        } else {
            b.emplace(i+1,1);
        }
    }
    long long int sum=r.size()*g.size()*b.size();
    long long int count=0;
    for (auto itr=r.begin();itr!=r.end();itr++) {
        for (int i=1;abs(itr->first-i-i)<=n;i++) {
            if (g[itr->first+i]==1&&b[itr->first+i+i]==1) {
                count++;
                //cout<<itr->first<<" "<<itr->first+i<<" "<<itr->first+i+i<<endl;
            }
            if (g[itr->first+i]==1&&b[itr->first-i]==1) {
                count++;
            }
            if (g[itr->first-i]==1&&b[itr->first+i]==1) {
                count++;
            }
            if (g[itr->first-i]==1&&b[itr->first-i-i]==1) {
                count++;
                //cout<<itr->first<<" "<<itr->first-i<<" "<<itr->first-i-i<<endl;
            }
            if (g[itr->first-i-i]==1&&b[itr->first-i]==1) {
                count++;
            }
            if (g[itr->first+i+i]==1&&b[itr->first+i]==1) {
                count++;
            }
        }
    }
    cout<<sum-count<<endl;
}