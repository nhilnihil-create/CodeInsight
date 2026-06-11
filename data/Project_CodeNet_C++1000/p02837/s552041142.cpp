#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[20][20];
    int y[20][20];
    int a[20];
    bool all_not_told = true;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(a[i] > 0) all_not_told = false;
        for(int j = 1;j <= a[i]; j++){
            cin >> x[i][j] >> y[i][j];
        }
    }
    
    if(all_not_told){
        cout << n << endl;
        return 0;
    }

    if(n == 1){
        cout << 1 << endl;
    }

    int max_honest_count = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for(int bit = 1; bit < (1<<n); ++bit){        
        bool ishonest[20];
        for(int i = 1;i <= n; i++){
            ishonest[i] = false;
        }

        int honest_count = 0;
        for(int i = 0;i < n; i++){
            if(bit & (1<<i)) { // i が bit に入るかどうか
                ishonest[i+1] = true;
                honest_count++;
            }
        }
        
        bool contradiction = false;
        for(int i = 1;i <= n; i++){
            if(!ishonest[i]) continue;
            for(int j = 1;j <= a[i]; j++){
                if(y[i][j] == 1){   //honest
                    if(!ishonest[x[i][j]]){
                        contradiction = true; 
                    }
                }else{  //not know whether honest or a lier
                    if(ishonest[x[i][j]]){
                        contradiction = true;
                    }
                }
            }
        }

        if(!contradiction) max_honest_count = max(honest_count, max_honest_count);
    }
    cout << max_honest_count << endl;
    return 0;
}