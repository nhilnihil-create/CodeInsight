#include <iostream>

using namespace std;

int main()
{
    int64_t N;

    cin >> N;

    int64_t k;
// cout << "f4" << endl;
    int64_t sum = 0;
    for ( int64_t i = 1; i <= N; i ++ ) { 
        // cout << i << endl;
        {
            // iの倍数でN以下のものの総和を等差数列で計算
            int64_t d = i;
            while ( d <= N ) {
                sum += d;
        //         cout << " " << i << " add " << d << endl;
                d += i;
            }

        }
    }

    cout << sum << endl;

  	return 0;
}

