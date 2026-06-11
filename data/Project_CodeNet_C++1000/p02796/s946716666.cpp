#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;



struct indiv{
    int end,start,x,l;
};

bool asc(const indiv& left,const indiv& right){
    return left.end < right.end;
};

int main(){
    int n;
    cin >> n;
    vector<indiv> robo(n);
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> robo[i].x >> robo[i].l;
        robo[i].start = robo[i].x-robo[i].l;
        robo[i].end = robo[i].x+=robo[i].l;
    }

    sort(robo.begin(),robo.end(),asc);

    int now_end = robo[0].end;
    ans++;

    for(int i = 1; i < n; i++){
        if(robo[i].start >= now_end){
            now_end = robo[i].end;
            ans++;
        }
    }

    cout << ans << endl;

}