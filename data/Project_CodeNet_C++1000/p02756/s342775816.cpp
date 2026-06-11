#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ll=long long;
using namespace std;

int main(){
    string S;
    int Q;
    cin>>S>>Q;

    int T,F;
    char C;
    vector<char> front;
    vector<char> back;
    int rev=1;
    for(int i=0;i<Q;i++){
        cin>>T;
        if(T==1){
            rev*=-1;
        }else{
            cin>>F>>C;
            if(rev==1){
                if(F==1){
                    front.push_back(C);
                }else{
                    back.push_back(C);
                }
            }else{
                if(F==2){
                    front.push_back(C);
                }else{
                    back.push_back(C);
                }
            }
        }
    }

    string ans;
    for(int i=front.size()-1;i>=0;i--){
        ans.push_back(front[i]);
    }
    for(int i=0;i<S.size();i++){
        ans.push_back(S[i]);
    }
    for(int i=0;i<back.size();i++){
        ans.push_back(back[i]);
    }
    if(rev==-1){
        reverse(ans.begin(),ans.end());
    }
    cout<<ans<<endl;

    return 0;
}