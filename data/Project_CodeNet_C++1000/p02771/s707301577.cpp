#include<iostream>
#include<set>

#define ll long long
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int a,b,c; std::cin >> a >> b >> c;
    std::set<int> st;
    st.insert(a); st.insert(b); st.insert(c);
    if(st.size() == 2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}