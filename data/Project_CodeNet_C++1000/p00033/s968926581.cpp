/*
* @Author: key
* @Date:   2016-03-04 11:52:34
* @Last Modified by:   key
* @Last Modified time: 2016-03-04 12:49:05
*/

#include <iostream>

using namespace std;

int c[10];

int a[10],b[10];

bool flag;

void dfs(int x,int y,int z){
    if(x > 9){
        flag = true;
        return;
    }

    if(flag)
        return;

    if(y < 0 || c[x] > a[y]){
        a[y+1] = c[x];
        dfs(x+1,y+1,z);
    }

    if(z < 0 || c[x] > b[z]){
        b[z+1] = c[x];
        dfs(x+1,y,z+1);
    }

}

int main(){

    int n;

    cin >> n;

    while(n--){
        flag = false;
        for(int i = 0; i < 10; i++){
            cin >> c[i];
            a[i] = 0;
            b[i] = 0;
        }
        dfs(0,-1,-1);
        if(flag)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}