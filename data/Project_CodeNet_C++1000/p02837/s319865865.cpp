#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision

using namespace std;
using pint = pair<int,int>;
int main(){
    int  n ; cin >> n;
    int bit;
    int a,x,y;
    vector<vector<pint>> v;
    v.resize(n);
    for (int i = 0; i < n; i++) //全員の証言を聞く
    {
        cin >> a;
        v[i].resize(a);
        for (int j = 0; j < a; j++) //iのaコの証言
        {
            cin >> v[i][j].first >> v[i][j].second;
        }
    }

    int count ;
    int max=0;
    int nflag;
    for ( bit = 0; bit < (1<<n); bit++) //（bit全探索）決め打ちと証言間の整合性のチェック
    {
        count =0;
        nflag =0;
        for (int i = 0; i < n; i++)
        {   
            if(bit&(1<<i)){ //選んだ人の話だけ聞く      
                for(auto xy : v[i]){
                    int x = xy.first-1;
                    int y = xy.second;
                    if(y==1 && !(bit&(1<<x))) {
                        nflag++;
                        break;
                    }
                    if(y==0 && bit&(1<<x)) {
                        nflag++;
                        break;
                    }
                }
                if(nflag) break;   //整合性が取れなかったので次の決め打ちへ
                count++;     
            }
        }
        if(!nflag && count > max) max = count;
    }

    cout << max << endl;


    return 0;
}