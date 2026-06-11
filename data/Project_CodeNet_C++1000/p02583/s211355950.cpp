#include<iostream>
#include<vector>
using namespace std;

bool triangle(int x, int y, int z){
    int maxl = max(x, max(y, z));
    if(x == y) return 0;
    if(x == z) return 0;
    if(z == y) return 0;
    if(maxl == x) return y + z > x;
    if(maxl == y) return x + z > y;
    if(maxl == z) return y + x > z;
    return -1;
}

int main(){
    
    int n,ans = 0;
    cin >> n;
    vector<int> l(n);
    for(int i = 0;i < n;i++) cin >> l[i];
    
    //3本選ぶ
    for(int i = 0;i < n - 2;i++){
        for(int j = i + 1;j < n - 1;j++){
            for(int k = j + 1;k < n;k++ ){
                //三角形を満たすかどうか調べる
                if(triangle(l[i], l[j], l[k])){ 
                    ans++;
                }
            }
        }
    }

    cout << ans  << endl;
    
    return 0;
}