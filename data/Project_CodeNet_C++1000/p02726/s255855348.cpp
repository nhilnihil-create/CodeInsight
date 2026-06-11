//
//  main.cpp
//  D - Line++
//
//  Created by 李远铄 on 2020/7/15.
//  Copyright © 2020 李远铄. All rights reserved.
//

#include <iostream>
#include <vector>
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << "  "<<'\n';
#else
#define debug(x) ;
#endif

using namespace std;
int N;
int X,Y;
vector<int>ans;
int main(int argc, const char * argv[]) {
    scanf("%d %d %d",&N,&X,&Y);
    ans.resize(N);
    for (int i=0; i<N; i++) {
        ans[i]=0;
    }
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            int len=abs(X-i)+1+abs(j-Y);
            ans[len<j-i?len:j-i]++;
        }
    }
    for (int i=1; i<N; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
