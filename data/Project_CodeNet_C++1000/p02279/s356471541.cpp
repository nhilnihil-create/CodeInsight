#include <iostream>
#include <vector>
#include <array>
#include <list>

#define MAX 100000

typedef struct _contents
{
        int number;
        int parents;
        int depth;
        int status;
        std::vector< int > con_node;
} contents_t;

using namespace std;
array< contents_t, MAX > node;
int main()
{
        array< contents_t, MAX > node;
        int num, degree, id, count = 0, tmp, i;

        for ( i = 0 ; i < node.size() ; i++ )
        {
                node[i].number = i;
                node[i].parents = -1;
                node[i].depth = 0;
        }

        cin >> num;
        count = num;
        while ( num > 0 )
        {
                cin >> id;
                cin >> degree;
                for ( int j = 0 ; j < degree ; j++ )
                {
                        cin >> tmp;
                        node[id].con_node.push_back( tmp );
                        node[tmp].parents = id;
                }
                num = num - 1;
        }

        for ( int j = 0 ; j < count ; j++ )
        {
                printf( "node %d: parent = %d, depth = ", j, node[j].parents );

                tmp = j;
                while ( node[tmp].parents != -1 )
                {
                        tmp = node[tmp].parents;
                        node[j].depth++;
                }
                cout << node[j].depth << ", ";
                if ( node[j].parents == -1 )
                {
                        printf( "root, ");
                }
                else
                {
                        if ( node[j].con_node.size() == 0 )
                        {
                                printf( "leaf, ");
                        }
                        else if ( node[j].con_node.size() != 0 )
                        {
                                printf( "internal node, ");
                        }
                }

                printf( "[" );
                for ( i = 0 ; i < node[j].con_node.size() ; i++ )
                {
                        if ( i == node[j].con_node.size()-1 || node[j].con_node.size() == 0 )
                        {
                                printf( "%d", node[j].con_node[i] );
                        }
                        else
                        {
                                printf( "%d, ", node[j].con_node[i] );
                        }
                }
                printf( "]\n" );
        }

        return 0;
}

