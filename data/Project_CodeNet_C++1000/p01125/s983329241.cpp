#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        if(n==0)
            break;
        int a[n][2];
        for(int i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1];
        }

        //ハント開始
        int x=10; int y=10; //ロボットの座標
        char c;
        int l;
        int f=0;
        int m; cin >> m;
        for(int i=0;i<m;i++){
            cin >> c >> l;
            switch (c){
                case 'N': for(int j=1;j<=l;j++){
                            for(int k=0;k<n;k++){
                                if(a[k][0]==x && a[k][1]==y+j){
                                    f++;
                                    a[k][0]=100;
                                }
                            }
                        }
                        y+=l;
                        break;
                case 'S': for(int j=1;j<=l;j++){
                            for(int k=0;k<n;k++){
                                if(a[k][0]==x && a[k][1]==y-j){
                                    f++;
                                    a[k][0]=100;
                                }
                            }
                        }
                        y-=l;
                        break;
                case 'E': for(int j=1;j<=l;j++){
                            for(int k=0;k<n;k++){
                                if(a[k][0]==x+j && a[k][1]==y){
                                    f++;
                                    a[k][0]=100;
                                }
                            }
                        }
                        x+=l;
                        break;
                case 'W': for(int j=1;j<=l;j++){
                            for(int k=0;k<n;k++){
                                if(a[k][0]==x-j && a[k][1]==y){
                                    f++;
                                    a[k][0]=100;
                                }
                            }
                        }
                        x-=l;
                        break;
            }

        }
        if(n==f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}