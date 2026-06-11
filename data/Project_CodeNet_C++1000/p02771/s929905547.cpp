#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> st;
    for(int i = 0;i<3;i++){
        int a; cin >> a;
        st.insert(a);
    }    
    if(st.size()==2) puts("Yes");
    else puts("No");
    return 0;
}