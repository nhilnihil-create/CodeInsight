///                    بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
///                   لآ اِلَهَ اِلّا اللّهُ مُحَمَّدٌ رَسُوُل اللّهِ




#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
    int x;
    cin >> x;

    if(x % 10 == 3) cout << "bon" << endl;
    else if(x%10== 0||x%10== 1||x%10== 6||x%10==8) cout << "pon" << endl;
    else cout << "hon" << endl;



	return 0;
}

