#include<iostream>
using namespace std;
#include<vector>

#define infinity 0x3fffffff
#define V 100000
#define C 10000
#define E 500000

struct edge
{
    int t;  //target vertices of i-th edge
    int d;  //the cost of the i-th edge
    int next; //The next edge of the same starting point
};
int count;
int minn; //minn represents the min cost of the point to the source point in the set of P
int k;	//k records this point
		
int v;//v represents the number of vertices
int e;//e represents the number of edges
int	r;//r represents the source of the graph
vector<int> head;  //The location of the edge corresponding to the node in the storage array
vector<edge> edges;  //information of edge
vector<int> hash;

void add_edge(int s,int t,int d);
int hash_transfer(int point);
int hash_map(int k,int point,int i);

int main()
{
	while(1)
	{
		//cout<<"Please input the number of the points and edges and the source of the map in order:"<<endl;
		cin>>v>>e>>r;
		if(v<1||v>V||e<0||e>E)
		{
			//cout<<"The input value is out of range!"<<endl;
			cin.clear();
		}
		else 
			break;
	}
	int i,j; 
	vector<int> dis(v,infinity);  //the cost of the shortest path from the source to each vertex	
	vector<bool> flag(v,false);  //whether the point is in the set of shortest points away from the source,S for yes,P for no
	vector<int> queue(v); 
	head.resize(v,-1);
	edges.resize(e);
	hash.resize(v,-1);
	for(i=0;i<e;i++) //initialize edges
		edges[i].next=-1;

	int point1,point2,cost;
	i=1;
	while(1)
	{
		for(;i<=e;i++)
		{
			//cout<<"Please input the origin point and terminal point of edge["<<i<<"] and its value in order:"<<endl;
			cin>>point1>>point2>>cost;
			if(point1==point2)
			{
				//cout<<"No self-loop!"<<endl;
				cin.clear();
				e--;
				break;
			}
			//point1=hash_transfer(point1);
			//point2=hash_transfer(point2);
			if(point1<0||point2<0)
			{
				//cout<<"Out of range!"<<endl;
				cin.clear();
				e--;
				break;
			}

			for(j=head[point1];j>=0;j=edges[j].next)
				if(point2==edges[j].t)
				{
					//cout<<"No parallel sides!"<<endl;
					cin.clear();
					break;
				}
			if(j>=0)
			{
				e--;
				break;
			}
			add_edge(point1,point2,cost);
		}
		if(i>e)
			break;
	}
	//r=hash_transfer(r);
	dis[r]=0;
	int front =0,back = 0;
    queue[back++] = r;
     while (front != back)//There is no comparison between the source and the source point, so the total number of times is less  
    {
		int x = queue[front];
        flag[x] = 0;
        front = e==0?back:(front+1)%v;
        for(j=head[x];j>=0;j=edges[j].next)	//Find the min cost point from the source point 
										//and start updating the value of the source point to each point in the dis 
			if(dis[edges[j].t]>dis[x]+edges[j].d)
			{
				dis[edges[j].t]=dis[x]+edges[j].d;
				if (!flag[edges[j].t]) {
                    queue[back] = edges[j].t;
                    flag[edges[j].t] = 1;
                    back = (back+1)%v;
                }
			}
    }
	for (i=0;i<v;i++)  //output dis
    {  
		if(dis[i]<infinity)
			cout<<dis[i]<<"\r\n";
		else
			cout<<"INF"<<"\r\n";
    }    
    return 0;
}

void add_edge(int s,int t,int d) //add information of edge
{    
    edges[count].t=t;
    edges[count].d=d;
    edges[count].next=head[s];
    head[s]=count;
	count++;
}

int hash_transfer(int point)
{
	int j;
	for(j=0;j<v;j++)
		if(hash[j]==point)
		{
			point=j;
			break;
		}
	if(j>=v)
		point=hash_map(point%v,point,0);	
	return point;
}

int hash_map(int x,int point,int i)
{	
	if(hash[x]<0)
		hash[x]=point;
	else
		if(i<=v)
			x=hash_map((x+1)%v,point,i++);
		else 
			return -1;
	return x;
}