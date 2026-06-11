#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S){
    if(S.size()%2){
        cout<<NO<<endl;
        return;
    }
    for(int i=0;i<S.size();i+=2)
    {
        if(S[i]=='h'&&S[i+1]=='i')continue;
        cout<<NO<<endl;
        return;
    }
    cout<<YES<<endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
