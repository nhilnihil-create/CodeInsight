#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    long long int K;
    cin >> K;
    
    vector<long long int> vec;
    char pre=str[0];
    long long int cur=0;
    for(int i=0; i<str.size(); i++) {
        if(pre==str[i]) {
            cur++;
        } else {
            vec.push_back(cur);
            cur=1;
        }
        pre = str[i];
    }
    vec.push_back(cur);

    long long int ans=0;
    if(str[0]==str[str.size()-1]) {
        if(vec.size()==1) {
            ans = vec[0]*K/2;
        } else {
            for(int i=1; i<vec.size()-1; i++) {
                ans += vec[i]/2;
            }
            ans *= K;
            ans += vec[0]/2+vec[vec.size()-1]/2+(vec[0]+vec[vec.size()-1])/2*(K-1);
        }
    } else {
        for(int i=0; i<vec.size(); i++) {
            ans += vec[i]/2;
        }
        ans *= K;
    }
    
    cout << ans << endl;
    
    return 0;
    
}