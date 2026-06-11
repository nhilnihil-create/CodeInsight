#include<iostream>
using namespace std;
int main(){
    int h,w,k ;
    cin>> h >> w >> k;
    
    char a[h][w];
    for(int i = 0 ; i< h ; i++ ){
        for(int j = 0 ;j<w ; j++ ){
            cin>>a[i][j];
        }
    }
    
    int ans = 0;
    for( int row = 0 ; row < (1<<h) ; row ++ ){
        for( int col =0 ; col < (1<<w) ; col ++ ){
            int cnt = 0;
            for(int i = 0 ; i < h ; i++){
                for(int j = 0 ; j< w ; j++){
                    if( (row>>i)&1 && (col>>j)&1 && a[i][j] == '#'){
                        cnt++;
                    }
                }
            }
            
            if(cnt == k ){
                ans++;
            }
        }
    }

    cout << ans;
}