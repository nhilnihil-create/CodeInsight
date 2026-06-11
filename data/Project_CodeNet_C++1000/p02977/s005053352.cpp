#include<iostream>
using namespace std;
int n, nr, i, p, x, y, ok;
pair<int, int> w[200005];
int main(){
    cin>> n;
    if(n == 1){
        cout<<"No";
        return 0;
    }
    if(n == 6){
        cout<<"Yes\n1 2\n2 3\n3 7\n7 8\n8 9\n5 4\n4 7\n7 11\n11 10\n3 6\n4 12";
        return 0;
    }
    if(n % 2 == 0){
        p = 1;
        while(p * 2 <= n){
            p *= 2;
        }
        if(n == p){
            cout<<"No";
            return 0;
        }
        x = p;
        y = (n ^ p);
        w[++nr] = make_pair(x, y);
        w[++nr] = make_pair(y, n);
        w[++nr] = make_pair(n, x + n);
        w[++nr] = make_pair(x + n, y + n);
        w[++nr] = make_pair(y + n, 2 * n);
        w[++nr] = make_pair(x + 1, y + 1);
        w[++nr] = make_pair(y + 1, n);
        w[++nr] = make_pair(n, x + n + 1);
        w[++nr] = make_pair(x + n + 1, y + n + 1);
    }
    for(i = 2; i < n; i += 2){
        if(i == x || i == y){
            continue;
        }
        if(ok == 0){
            ok = 1;
            w[++nr] = make_pair(i, i + 1);
            w[++nr] = make_pair(i + 1, 1);
            w[++nr] = make_pair(1, i + n);
            w[++nr] = make_pair(i + n, i + n + 1);
            w[++nr] = make_pair(i + n + 1, n + 1);
        }
        else{
            w[++nr] = make_pair(i, i + 1);
            w[++nr] = make_pair(i + 1, 1);
            w[++nr] = make_pair(1, i + n);
            w[++nr] = make_pair(i + n, i + n + 1);
        }
    }
    if(n % 2 == 0){
        w[++nr] = make_pair(1, n);
    }
    cout<<"Yes\n";
    for(i = 1; i <= nr; i++){
        cout<< w[i].first <<" "<< w[i].second <<"\n";
    }
}
