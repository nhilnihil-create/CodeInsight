#include <iostream>

using namespace std;

int count_senbei(int senbei, int R) {
    int res=0;

    for(int i=0; i<R; ++i) {
        res+=senbei%2;
        senbei>>=1;
    }

    return max(res,R-res);
}

int main()
{
    int R,C;
    cin >> R >> C;

    while(R!=0 && C!=0) {
        int s[C]={0};
        int MAXR=0;

        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                int temp;
                cin >> temp;
                s[j]<<=1;
                s[j]+=temp;
            }

            MAXR<<=1;
            MAXR+=1;
        }

        int ans=0;

        for(int i=0; i<=MAXR; ++i) {
            int res=0;
            for(int j=0; j<C; ++j) {
                res+=count_senbei(s[j]^i,R);
            }
            ans=max(ans,res);
        }

        cout << ans << endl;

        cin >> R >> C;
    }

    return 0;
}