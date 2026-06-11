#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    set<char> st;
    char a,b,c,d;
    for (int i = 0;i < 4;i++){
        char tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    if (st.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;

   return 0;

}