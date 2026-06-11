#include <bits/stdc++.h>
#define FxZ ;
#define gby {
#define nMC }
#define suS /=
#define Shy +=
#define LJT -=
#define KUT *=
#define ckx !=
#define sNQ %=
#define imn ^=
#define sut |=
#define pJE &=
#define uVK ||
#define dSG &&
#define YFo *
#define Tfe /
#define EMl ++
#define Lih --
#define nea +
#define mFp -
#define Amc %
#define sBS ^
#define qhd ?
#define fyd &
#define ToM |
#define ouJ !
#define NXM ==
#define uGz >>
#define XvM <<
#define QTF <=
#define Ocl >=
#define AcB ->
#define OBL =
#define rGP <
#define VaS >


using namespace std FxZ 
long a[200005],n,k FxZ 
bool check(int m)
 gby 
 int sl OBL 0 FxZ 
 for(int i OBL 1 FxZ i QTF n FxZ i EMl )
 gby 
 sl OBL sl nea (a[i] Tfe m) FxZ 
 if(a[i] Amc m NXM 0) sl Lih FxZ 
 nMC 
 return (sl QTF k) FxZ 
 nMC 
int main()
 gby 
 long dau OBL 1,cuoi,giua,M FxZ 
 cin uGz n uGz k FxZ 
 for(int i OBL 1 FxZ i QTF n FxZ i EMl )
 gby 
 cin uGz a[i] FxZ 
 cuoi OBL max(cuoi,a[i]) FxZ 
 nMC 
 while(dau QTF cuoi)
 gby 
 giua OBL (dau nea cuoi) Tfe 2 FxZ 
 if(check(giua) NXM true)
 gby 
 M OBL giua FxZ 
 cuoi OBL giua mFp 1 FxZ 
 nMC 
 else dau OBL giua nea 1 FxZ 
 nMC 
 cout XvM M FxZ 
 nMC 
