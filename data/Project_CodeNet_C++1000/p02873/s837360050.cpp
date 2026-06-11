#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<long long int> vec;
    long long int cnt=1;
    char cur=str[0];
    for(int i=1; i<str.size(); i++) {
        if(str[i]==cur) {
            cnt++;
        } else {
            vec.push_back(cnt);
            cnt=1;
            cur = str[i];
        }
    }
    vec.push_back(cnt);

    long long int ans=0;
    if(str[0]=='>') {
        ans += (vec[0]+1)*vec[0]/2;
        for(int i=1; i<vec.size()-1; i++) {
            long long int mx=max(vec[i], vec[i+1]), mn=min(vec[i], vec[i+1]);
            ans += (mx+1)*mx/2 + (mn-1)*mn/2;
            i++;
        }
        if(vec.size()%2==0) {
            ans += (vec[vec.size()-1]+1)*vec[vec.size()-1]/2;
        }
    } else {
        for(int i=0; i<vec.size()-1; i++) {
            long long int mx=max(vec[i], vec[i+1]), mn=min(vec[i], vec[i+1]);
            ans += (mx+1)*mx/2 + (mn-1)*mn/2;
            i++;
        }
        if(vec.size()%2) {
            ans += (vec[vec.size()-1]+1)*vec[vec.size()-1]/2;
        }
    }
    cout << ans << endl;


    return 0;
    
}