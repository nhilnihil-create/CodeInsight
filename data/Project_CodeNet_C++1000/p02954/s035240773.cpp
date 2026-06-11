#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n=(int)s.size();
    int r_count=0;
    int l_count=0;
    int change=-1;
    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        if(i==0){
            r_count++;
            continue;
        }
        if(s.at(i) == 'L'){
            if(l_count==0){
                ans.at(i-1) += (r_count+1)/2;
                ans.at(i) += r_count/2;
                change=i;
            }
            r_count=0;
            l_count++;
        }
        else{
            if(r_count==0){
                ans.at(change-1) += l_count/2;
                ans.at(change) += (l_count+1)/2;
            }
            l_count=0;
            r_count++;
        }
    }
    ans.at(change-1) += l_count/2;
    ans.at(change) += (l_count+1)/2;
    for(int i=0; i<n; i++){
        cout << ans.at(i) << ' ';
    }
    cout << endl;
}
