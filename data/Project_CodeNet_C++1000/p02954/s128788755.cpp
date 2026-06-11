#include<bits/stdc++.h>
#define re register
using namespace std;
int h[100010], t, cnt;
char a[100010];
struct node {
	int fro;
    int to;
}el[100010];
int main() {
        scanf("%s", a + 1);
        int cntl = 0;
        int sst = strlen(a + 1);
        memset(h, 0, sizeof(h));
        t = -1;
        for (re int i = 1; i <= sst; i++) {
         if (a[i] == 'L') {
             if (t == -1) {
                 el[++cnt].fro = i;
                 el[cnt].to = i;
                 t = 0;
			 }
			else el[cnt].to = i;
		}
		else t = -1;
		}
        el[0].to = 0;
     for (re int i = 1; i <= cnt; i++) {
         int dis = (el[i].fro - el[i - 1].to - 1);
         int disl = (el[i].to - el[i].fro + 1);
         if (dis % 2 == 1) {
             h[el[i].fro] += (dis / 2);
             h[el[i].fro - 1] += (dis / 2) + 1;
			}
		else {
             h[el[i].fro] += (dis / 2);
             h[el[i].fro - 1] += (dis / 2);
		}
         if (disl % 2 == 1) {
             h[el[i].fro - 1] += (disl / 2);
             h[el[i].fro] += (disl / 2) + 1;
			}
			else {
             h[el[i].fro - 1] += (disl / 2);
             h[el[i].fro] += (disl / 2);
			}

		}
     for (re int i = 1; i <= sst; i++) {
         printf("%d ", h[i]);
		}

 return 0;
	}