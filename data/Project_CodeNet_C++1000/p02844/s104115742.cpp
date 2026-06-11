#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;
    for(int a=0; a<10; a++){
        for(int b=0; b<10; b++){
            for(int c=0; c<10; c++){
                int k=0;
                for(int i=0; i<n; i++){
                    int x = s[i]-'0';
                    if((k==0 & a==x)|(k==1 & b==x)|(k==2 & c==x)) k++;
                    if(k==3){
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}