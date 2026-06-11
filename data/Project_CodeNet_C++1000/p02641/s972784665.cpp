#include<iostream>
#include<vector>
#define INF 1000000
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    int i, plus, minus;
    for(i=0;i<n;i++){
        cin >> p.at(i);
    }

    int ans=INF;
    int count = 0;
    while(1){
        minus=INF;
        plus=INF;
        for(i=0;i<n;i++){
            if(p.at(i)==x-count){
                minus = p.at(i);
            }
            if(p.at(i)==x+count){
                plus = p.at(i);
            }
        }
        if(minus==INF){
            ans=x-count;
            break;
        }
        if(plus==INF){
            ans=x+count;
            break;
        }
        count++;
    }

    cout << ans << endl;
}