#include <iostream>
#define ll long long
using namespace std;
ll a,c[1000][1000],p[10000],la[1000],day,id;
int main() {
    cin>>a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a-1;j++){
            cin>>c[i][j];
            c[i][j]--;
        }
    }
    bool tor = 1;
    while(tor){
        day++;
        tor = 0;
        for(int i=0;i<a;i++){
            if(p[i] < a-1){
                id = c[i][p[i]] ;
                if(la[i] < day && la[id]<day && p[id]<a-1 && c[id][p[id]] == i){
                    la[id] = day;
                    la[i] = day;
                    p[i] ++;
                    p[id]++;
                    tor = 1;
                }
            }
        }
        
    }
    for(int i=0;i<a;i++){
        if(p[i] != a-1){
            cout<<-1;
            return 0;
        }
    }
    cout<<day-1;
}