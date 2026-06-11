#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> a(N);
    set<int> dic;
    bool check = true;

    for(int i=0; i<N; i++){
        cin>>a[i];
        dic.insert(a[i]);
    }

    /*
    多くても三種類しかないことを考える
    */

    int s = (int)dic.size();

    if(s > 3) check = false;

    else{

        /*種類が一つだけの時、すべてゼロじゃないとだめ*/
        if(s == 1){
            for(int i=0; i<N; i++){
                if(a[i] != 0) check = false;
            }
        }

        /*種類が二種類の時、N/3枚が0、2N/3枚が同じ数
        種類が三種類の時、三つの種類がそれぞれN/3枚必要
        */

        if(s == 2 || s == 3){
            map<int,int> mp;

            if(N%3 != 0) check = false;
            
            for(int i=0; i<N; i++){
                mp[a[i]]++;
            }

            if(s == 2){
                for(auto a : mp){ 
                    if(a.first == 0){
                        if(a.second != N/3) check = false;
                    }

                    else{
                        if(a.second != 2*N/3) check = false;
                    }
                }
                
            }

            if(s == 3){
                vector<int> tmp;

                for(auto a : mp){
                    if(a.first == 0) check = false;
                    if(a.second != N/3) check = false;
                    tmp.push_back(a.first);
                }

                int sum = 0;

                for(int i=0; i<3; i++){
                    sum ^= tmp[i];
                }

                if(sum != 0) check = false;
            }
        }
    }

    cout<<(check ? "Yes" : "No")<<endl;

    return 0;
}