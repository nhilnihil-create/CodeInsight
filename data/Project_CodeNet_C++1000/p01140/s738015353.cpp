#include <iostream>
using namespace std;

int main()
{   
    int n, m;
    int a, b;
    int i, j, k, l;
    int h_now = 0, w_now = 0;
    int h[1505], w[1505];
    int haba_h[1500000] = {};
    int haba_w[1500000] = {};
    int counter = 0;
    while(1){
        for(i = 0; i < 1500000; i++){
            haba_h[i] = 0;
            haba_w[i] = 0;
        }
        counter = 0;
        w_now = 0;
        h_now = 0;
        h[0] = 0;
        w[0] = 0;
        cin >> n >> m;
        if(n == 0 && m == 0){ break ;}
        
        //????????§?¨?
        for(i = 1; i <= n; i++){
            cin >> a;
        
        h_now = h_now + a;
        h[i] = h_now;
        }

        //w?????§?¨?
        for(i = 1; i <= m; i++){
            cin >> b;

            w_now = w_now + b;
            w[i] = w_now;
        }
        
        //?????????????????????????????????
        for(i = 0; i < n; i++){
            for(j = i; j <= n; j++){
                haba_h[h[j] - h[i]]++;
            }
        }

        for(i = 0; i < m; i++){
            for(j = i; j <= m; j++){
                haba_w[w[j] - w[i]]++;
            }
        }

        for(i = 1; i < 1500000; i++){
            counter = counter + haba_h[i] * haba_w[i];
        }
        cout << counter << endl;
    }
    return 0;
}
       

    