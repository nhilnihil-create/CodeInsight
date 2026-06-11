#include<iostream>
#include<string>
#include<map>
using namespace std;

int par[100000];    //添え字として0~99999を許容する

int root(int i){
    if(par[i]==i){
        return i;
    }
    return par[i] = root(par[i]);

}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        par[i] = i;
    }
    for(int i = 0; i < m; ++i){
        int k1, k2;
        cin >> k1 >> k2;
        k1--;k2--;
        par[root(k1)] = root(k2);
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(root(i)==i){
            cnt++;
        }
    }
    cout << (cnt - 1);
}