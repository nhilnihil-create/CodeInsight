#include<bits/stdc++.h>
using namespace std;

#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("READ.txt", "r", stdin)
#define Write          freopen("OUTPUT.txt", "w", stdout)
#define INF            9999
#define Co(x)          cout<<x<<endl;
#define Cos(x)         cout<<x<<" ";
#define SORT(v)        sort(v.begin(),v.end())

typedef vector<long long>vii;
typedef pair<long long,long long>Pair;
//typedef map<long long,long long>Map;



//int dr[]={1,0,-1, 0 };
//int dc[]={0,1, 0,-1 };

//int dr[]={1,1,0,-1,-1,-1, 0, 1};
//int dc[]={0,1,1, 1, 0,-1,-1,-1};

/*while(1) {
    if(!getline(cin,s)||s.empty()) break;
}*/

/*const int RT = 10000000;
vector<int>prime;
bitset<10000003> status;

void sieve()
{
    int rt = sqrt(RT);
    //for(int i = 4; i <= rt; i+=2) status[i]=true;
    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j+=(i<<1))
                status[j] = true;
    prime.push_back(2);
    for(int i = 3; i <= RT; i+=2)
        if(!status[i])
            prime.push_back(i);
}

void Binary_Con(int n)
{
    int binaryNum[70];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

bool isSmaller(string str1, string str2)
{
 int n1 = str1.length(), n2 = str2.length();
 if (n1 < n2)
 return true;
 if (n2 < n1)
 return false;

 for (int i=0; i<n1; i++)
 if (str1[i] < str2[i])
  return true;
 else if (str1[i] > str2[i])
  return false;

 return false;
}

string findDiff(string str1, string str2)
{
 if (isSmaller(str1, str2))
  swap(str1, str2);
 string str = "";
 int n1 = str1.length(), n2 = str2.length();
 reverse(str1.begin(), str1.end());
 reverse(str2.begin(), str2.end());
 int carry = 0;
 for (int i=0; i<n2; i++)
 {
  int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
  if (sub < 0)
  {
   sub = sub + 10;
   carry = 1;
  }
  else
   carry = 0;
  str.push_back(sub + '0');
 }

 for (int i=n2; i<n1; i++)
 {
  int sub = ((str1[i]-'0') - carry);
  carry = 0;
  str.push_back(sub + '0');
 }
 reverse(str.begin(), str.end());
 return str;
}

int subtract( int x, int y)
{
    if (y == 0)
        return x;
    return subtract(x ^ y, (~x & y) << 1);

}

/// Modular add minus multiply
    const int M=1e9+7;
long long mod(long long x){
        return ((x%M + M)%M);
    }
long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
long long multy(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
long long minu(long long a, long long b){
        return mod(mod(a)-mod(b));
    }

long long power(long long x, long long y, long long p) // modular expopen
{
    long long res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}*/

/*int ROW,COL;
char arr[24][24];
struct Point
{
    int x;
    int y;
};

struct queueNode
{
    Point pt;
    int dist;
};

bool isValid(int row, int col)
{
    bool f;
    if(arr[row][col]=='.') f=true;
    else f=false;
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL)&&f;
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int BFS(Point src, Point dest)
{
    if (!arr[src.x][src.y] || !arr[dest.x][dest.y])
        return -1;

    bool visited[ROW+3][COL+3];
    memset(visited, false, sizeof visited);
    visited[src.x][src.y] = true;
    queue<queueNode> q;
    queueNode s = {src, 0};
    q.push(s);
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if (isValid(row, col)&&!visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return -1;
}*/


void solve()
{
   int n;
   cin>>n;
   vector<double>v;
   double sum=0,x;
   for(int i=0;i<n;i++) { cin>>x; v.push_back(x); }
   sort(v.begin(),v.end());
   sum=v[0];
   for(int i=1;i<n;i++)
   {
      sum+=v[i];
      sum/=2;
   }
   cout<<sum<<endl;
}

void kick_ass()
{
    fast
    #ifndef ONLINE_JUDGE
    //Read;
    //Write;
    #endif
    //int t; cin>>t; while(t--) solve();
    solve();
}

int main()
{
   kick_ass();
}
