#include<iostream>
//#include<cmath>
//#include<cstring>
//#include<vector>
#include<bits/stdc++.h>
//#include<algorithm>

using namespace std;
int main(){
  int x,c=0,i;
  cin>>x;
  string a;
  cin>>a;
  for(i=0;i<x-2;i++){
    if(a[i]=='A' && a[i+1]=='B' && a[i+2]=='C'){
        c++;
    }
  }

  cout<<c;


  return 0;
}

/*---------
 double n,m,a;
    cin>>n>>m>>a;
    cout<<(ceil(n/a)*ceil(m/a));

*/




/* int n;
  cin >> n;_.-
  for (int y=0; y<2*n+1; y++) {
    int c = 0;
    for (int x=0; x<2*n+1; x++) {
      int nx = x;
      int ny = y;
      if (nx>n) {
        nx -= (nx-n)*2;
      }
      if (ny>n) {
        ny -= (ny-n)*2;
      }
      int p = nx+ny-n;
      if (p>=0) {
        cout << p;
        c++;
        if (c >= 2*ny+1) {
          break;
        } else {
          cout << " ";
        }
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }
  return 0;
}*/
 /*----------my code--------------
  int n,a,b,c,d,space,i,j,apply;
    cin>>n;
    b=2*n+1;
    for(i=0;i<b;i++){
        space=2(n-1);
        for(j=0;j<b;j++){
            if(space>0){
                apply=space/2;
                for()
            }
        }

        int n,a,b,c,d,space,i,j,k,apply,index;
    cin>>n;
    b=2*n+1;
    for(i=0;i<b;i++){
        space=2(n-i);
        apply=space/2;
        for(j=0,k=0;j<b;j++,k++){
            if(space>1){
                    if(k<i){
                            index=apply+1;
                a[index]=k;
            index++;
            }
            if(k>=i){
                a[]
            }
            }
            }
        }
    }

   for
    }*/
    /*--------------------

    int main() {
	int n;
	cin>>n;
	int x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	int u=0,d=0,l=0,r=0,ans=0;
	for(int i=0;i<n;i++)
	{
		u=0;d=0;l=0;r=0;
		for(int j=0;j<n;j++)
		{
			if(x[i]==x[j]&&y[i]>y[j])d=1;
			if(x[i]==x[j]&&y[i]<y[j])u=1;
			if(y[i]==y[j]&&x[i]>x[j])l=1;
			if(y[i]==y[j]&&x[i]<x[j])r=1;
		}
		if(d&&u&&l&&r)ans++;
	}
	cout<<ans<<endl;
}-----------*/
