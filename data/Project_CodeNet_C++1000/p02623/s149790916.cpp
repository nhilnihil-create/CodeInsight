#include <bits/stdc++.h>
using namespace std;

int main (){
    long long N, M, K;
    cin >> N >> M >> K;
    int ans = 0;

    vector<long long> A(N+1,0);
    vector<long long> B(M+1,0);

    for (long long i = 1; i <= N; i++)
    {
        cin >> A.at(i);
        A.at(i) += A.at(i - 1);
        //A.at(i) = K - A.at(i);
    }
    for (long long i = 1; i <= M; i++)
    {
        cin >> B.at(i);
        B.at(i) += B.at(i - 1);
        //B.at(i) = K - B.at(i);
    }
    int a = N, b = 0;

    while(true) {

        if(A.at(a) + B.at(b) <= K) {
            ans = max(ans,a + b);
            b++;
        } else {
            a--;
        }
        if(b > M || a < 0) {
            break;
        }
    }

    

    //cout << "###" << endl;
    /*for(int i = N; i >= 0; i--) {
        for(int j = M; j > ans - i && j >= 0; j--) {
            if(A.at(i) + B.at(j) <= K) {
                ans = max(ans,i+j);
                //cout << i << ',' << j << endl;
                break;
            }
        }
    }
    */

    cout << ans << endl;
    return 0;




    //long long a = 0;
    //long long b = 0;
    long long left = K;
    bool aout = 0;
    bool bout = 0;
    for (long long i = 0; 0/*i < N+M*/; i++)
    {
        if (B.at(b) > A.at(a))
        {
          //  cout << 1 << endl;
            left -= A.at(a);
            if (left <0)
            {
                break;
            }
            
            a++;
            if (a == N)
            {
                aout = 1;
                break;
            }
            
        }else
        {
          //  cout << 2 << endl;
            left -= B.at(b);
            if (left < 0)
            {
                break;
                /* code */
            }
            
            b++;
            if (b == N)
            {
                bout = 1;
                break;
            }
            
        }
        
        
    }
    int bb = b;
    int aa = a;
    if (0/*aout*/)
    {
        for (long long i = 0; i < M-bb; i++)
        {
           // cout << 3 << ' ' << B.at(b) << endl;
            left -= B.at(b);
            if (left < 0)
            {
                break; 
            }
          //  cout << 324786278378 << endl;
            b++;
            
            
        }
        
        /* code */
    }
    if (0/*bout*/)
    {
        for (long long i = 0; i < N-aa; i++)
        {
         //   cout << 4  << endl;
            left -= A.at(a);
            if (left < 0)
            {
                break; 
            }
            a++;

            
        }
        
        /* code */
    }
    
    //cout << a + b << endl;
    return 0;
    

    
}