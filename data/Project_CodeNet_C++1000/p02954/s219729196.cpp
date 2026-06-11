#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string S;
    cin>>S;
    S.push_back('R');
    int r=1,l=0,C=0;
    int Cr=0,Cl=0;
    vector<int>ans(S.size()+1,0);
    for(int i=0;i<S.size();i++){
        if(S.at(i)=='L'&&Cl==0){
            Cr=0;
            Cl=1;
            C=i;
        }
        if(Cr==1){
            r++;
        }
        if(S.at(i)=='R'){
            Cr=1;
            if(Cl==1){
                if(i!=0){
                   
                    ans[C]=r/2+r%2+l/2;
                    ans[C-1]=r/2+l%2+l/2;
                    if((r+l)%2!=0){
                        swap(ans[C],ans[C-1]);
                    }
                }
                Cr=1;
                Cl=0;
                r=1;
                l=0;
            }
        }
        if(Cl==1){
            l++;
        }
    }
    for(int i=0;i<S.size()-1;i++){
        cout<<ans[i]<<" ";
    }
}